/**
 * State machine example implementing a stop watch. The example is taken from
 * the boost library's online documentation for statechart.
 * This watch has two buttons: start/stop and reset. These buttons act as events
 * in our stop watch.
 * The watch has an initial state: Active and two internal states: running and 
 * stopped.
 */

#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/event.hpp>
#include <boost/statechart/transition.hpp>
#include <ctime>
#include <iostream>

namespace sc = boost::statechart;

/* define events */
struct EvStartStop: sc::Event<EvStartStop> {};
struct EvReset: sc::Event<EvReset> {};

/*
 * struct defined as an interface to get information out of the state machine
 * each state will extend this struct and implement its method to return elapsed
 * time
 */
struct IElapsedTime
{
	virtual double elapsed_time() const = 0;
};

/* forward declaration of the initial state*/
struct active;
/* state machine */
struct stopWatch: sc::state_machine<stopWatch, active>
{
};

/* note: states are defined outside to inside because the context of a
 * state needs to be defined completely(not just forward declared) before 
 * defining the state itself. So to say, the outer states are defined before
 * the nested states. You can do it breadth first or depth first */
/* forward declaration of internal states */
struct stopped;
/* simple_state class can take upto 4 arguments. first arg is the context for
 * this state, second arg is the state machine to which the state belongs and
 * thrid arg is the initial state for this state */
struct active: sc::simple_state<active, stopWatch, stopped>
{
	public:
	typedef sc::transition<EvReset, active> reactions;
	active():
		elapsed_time(0.0) {};
	/* return elapsed time */
	double elapsed_time() const {return elapsed_time};
	/* return reference to elapsed time */
	double &elapsed_time() {return elapsed_time};

	private:
	double elapsed_time;
};
/* definition for stopped state. note that the context param is the containing
 * state's name */
struct stopped: sc::simple_state<active, stopWatch>
{
	typedef sc::transition<EvStartStop, running> reactions;
};
/* definition of running state */
struct running: sc::simple_state<active, stopWatch>
{
	public:
	typedef sc::transition<EvStartStop, stopped> reactions;
	running():
		start_time(std::time(0)) {};
	~running()
	{
		/* context<>() can be used by a state to access its containing state or
		 * the state machine itself; just a derived class does */
		context<active>().elapsed_time() += std::difftime(std::time(0), start_time);
	}

	private:
	double start_time;
};

/* main method */
int main
{
	stopWatch watch;
	watch.initiate();	// start the state machine
	watch.process_event(EvStartStop);	// process various events
	watch.process_event(EvStartStop);
	watch.process_event(EvStartStop);
	watch.process_event(EvReset);
	return 0;
}
