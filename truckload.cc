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
    bool
    operator<(const Box& box2)
    {
        return (volume() < box2.volume());
    }
    friend std::ostream&
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
private:
    class Package
    {
    public:
        explicit Package(std::shared_ptr<Box> box)
            : box(box)
        {
            next = nullptr;
            prev = nullptr;
        }
        std::shared_ptr<Package> next;
        std::shared_ptr<Package> prev;
        std::shared_ptr<Box> box;
    };
public:
    class Iterator
    {
    friend class Truckload;
    public:
        void
        operator++()
        {
            if (current) {
                current = current->next;
            }
        }
        void
        operator--()
        {
            if (current) {
                current = current->prev;
            }
        }
        std::shared_ptr<Box>
        operator*()
        {
            if (current) {
                return current->box;
            } else {
                return nullptr;
            }
        }
        bool
        operator!=(const Iterator& it)
        {
            return (current != it.current);
        }

    private:
        Iterator(std::shared_ptr<Package> current)
                    : current(current)
                {}

        std::shared_ptr<Package> current;
    };
public:
    Truckload()
    {
        firstPackage = nullptr;
        lastPackage = nullptr;
    }
    Iterator
    begin()
    {
        return Iterator(firstPackage);
    }
    Iterator
    rbegin()
    {
        return Iterator(lastPackage);
    }
    Iterator
    end()
    {
        return Iterator(nullptr);
    }
    Iterator
    erase(Iterator &it)
    {
        std::shared_ptr<Package> nextPackage = it.current->next;
        std::shared_ptr<Package> prevPackage = it.current->prev;
        if (prevPackage) {
            prevPackage->next = nextPackage;
        }
        if (nextPackage) {
            nextPackage->prev = prevPackage;
        }
        it.current.reset();
        return Iterator(nextPackage);
    }
    void
    addBox(shared_ptr<Box> box)
    {
        auto p = std::make_shared<Package>(box);
        if (lastPackage) {
            lastPackage->next = p;
            p->prev = lastPackage;
            lastPackage = lastPackage->next;
        } else {
            firstPackage = p;
            lastPackage = p;
        }
    }
    shared_ptr<Box>
    removeBox()
    {
        if (!firstPackage) {
            return nullptr;
        }
        auto b = firstPackage->box;
        if (lastPackage == firstPackage) {
            lastPackage = nullptr;
        }
        firstPackage = firstPackage->next;
        if (firstPackage) {
            firstPackage->prev = nullptr;
        }
        return b;
    }
private:
    std::shared_ptr<Package> firstPackage;
    std::shared_ptr<Package> lastPackage;
};

Truckload::Iterator
findLargestBox(Truckload::Iterator it1,
                Truckload::Iterator it2)
{
    auto largestBox = it1;
    for(;it1 != it2; ++it1)
    {
        if ((*largestBox)->volume() < (*it1)->volume()) {
            largestBox = it1;
        }
    }
    return largestBox;
}

int
main (int argc, char *argv[])
{
    auto truckload = make_shared<Truckload>();
    truckload->addBox(make_shared<Box>("Box1", 1, 2, 3));
    truckload->addBox(make_shared<Box>("Box2", 3, 2, 3));
    truckload->addBox(make_shared<Box>("Box3", 2, 2, 3));
    auto largestBox = findLargestBox(truckload->begin(), truckload->end());
    for (auto it = truckload->begin(); it != truckload->end(); ++it)
    {
        std::cout << *(*it);
    }
    std::cout << "Printing boxes in reverse order" << std::endl;
    for (auto rit = truckload->rbegin(); rit != truckload->end(); --rit)
    {
        std::cout << *(*rit);
    }
    std::cout << "Largest Box: " << *(*largestBox);
    std::cout << "Removing largest box" <<  std::endl;
    truckload->erase(largestBox);
    for (auto it = truckload->begin(); it != truckload->end(); ++it)
    {
        std::cout << *(*it);
    }
    std::cout <<  std::endl;
}
