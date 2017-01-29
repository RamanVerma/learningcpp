/**
 * Basic example of state machine with a single state.
 * The state prints messages on entry and exit.
 */
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <iostream>

namespace sc = boost::statechart;

/* forward declaration of state and the state machine */
struct Greeting;
/* boost/statechart follows template pattern wherein first param passed to 
 * the base class template is the deriving class. Second param passed here to
 * base class indicates initial state for the state machine. */
struct Sm : sc::state_machine<Sm, Greeting> {};
/* second param to simple_state defines the context(place) of the state. It can
 * be a container state or a state machine */
struct Greeting : sc::simple_state<Greeting, Sm>
{
	/* constructor is called when a state is entered */
	Greeting ()
	{
		std::cout << "Hello World!" << std::endl;
	}
	/* destructor is called when a state is exited */
	~Greeting ()
	{
		std::cout << "Good Bye!" << std::endl;
	}
};

int
main()
{
	Sm myMachine;
	/* start the machine */
	myMachine.initiate();
	/* machine will be destructed as we exit calling its destructor */
	return 0;
}
