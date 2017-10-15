#include <iostream>
#include <functional>
#include <memory>
#include <vector>

using namespace std;

class Box
{
public:
    Box(string desc, int x, int y, int z)
        : desc(desc),
        x(x),
        y(y),
        z(z),
        timesDelivered(0)
    {}
    int
    numTimesDelivered() const
    {
        return timesDelivered;
    }
    string
    description() const
    {
        return desc;
    }
    int
    volume() const
    {
        return x * y * z;
    }
    void
    markDelivered()
    {
        timesDelivered++;
    }
    friend
    std::ostream&
    operator<<(std::ostream &os, const Box& box)
    {
        os << "Box: [" << box.description() << "::" << box.volume() << "]" << endl;
        return os;
    }
private:
    int x;
    int y;
    int z;
    string desc;
    int timesDelivered;
};

class Truckload
{
public:
    Truckload()
    {}
    void
    addBox(shared_ptr<Box> box)
    {
        boxes.push_back(box);
    }
    shared_ptr<Box>
    removeBox()
    {
        if (boxes.empty()) {
            return nullptr;
        }
        auto b = boxes.back();
        boxes.pop_back();
        return b;
    }
private:
    std::vector<std::shared_ptr<Box>> boxes;
};

void
logDelivery(Box &box)
{
    cout << box << endl;
}

class DeliveryTruck
{
public:
    DeliveryTruck(std::shared_ptr<Truckload> truckload)
        : truckload(truckload)
    {}
    DeliveryTruck() = delete;

    void
    registerOnDelivered(std::function<void(Box&)> cb)
    {
        callbacks.push_back(cb);
    }

    void
    deliverBox()
    {
        auto box = truckload->removeBox();
        if (!box) {
            return;
        }
        for(auto &cb : callbacks)
        {
            cb(*box);
        }
    }
private:
    std::vector<std::function<void(Box&)>> callbacks;
    std::shared_ptr<Truckload> truckload;
};

int
main (int argc, char *argv[])
{
    auto cb = [] (Box &box) 
    {
        box.markDelivered();
        cout << box.description() << " delivered " << box.numTimesDelivered() << " times" << endl;
    };

    auto truckload = make_shared<Truckload>();
    truckload->addBox(make_shared<Box>("Box1", 1, 2, 3));
    truckload->addBox(make_shared<Box>("Box2", 2, 2, 3));
    DeliveryTruck truck = DeliveryTruck(truckload);
    truck.registerOnDelivered(cb);
    truck.registerOnDelivered(logDelivery);
    truck.deliverBox();
    truck.deliverBox();
}
