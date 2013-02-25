#ifndef STATE_H
#define STATE_H
namespace ao
{
	namespace core
	{
		/*
		Abstract State Class Used with Finite State Machine
		*/


		struct Telegram;

		template <class TYPE>
		class State
		{
		public:
			virtual ~State() {}
			//Dxecute when the state is entered
			virtual void Enter(TYPE*)=0;
			//States normal update function (Normally called after Enter and preceds Exit)
			virtual void Execute(TYPE*)=0;
			//Executed when the state is exited.
			virtual void Exit(TYPE*)=0;
			//this executes if the agent receives a message from the message dispatcher
			virtual bool OnMessage(TYPE*, const Telegram&)=0;
		};
#endif

#ifndef STATEMACHINE_H
#define STATEMACHINE_H
		/*
		Abstract State Machine used to inheart and manage your states
		*/
#include <cassert>
#include <string>
		//#include <typeinfo>

#include "aoTelegram.h"


		template <class TYPE>
		class StateMachine
		{
		private:

			//a pointer to the agent that owns this instance
			TYPE*          m_pOwner;
			//a pointer to the current state agent is in.
			State<TYPE>*   m_pCurrentState;
			//a pointer of the last state the agent was in
			State<TYPE>*   m_pPreviousState;
			//this is called every time the FSM is updated
			State<TYPE>*   m_pGlobalState;

		public:

			StateMachine(TYPE* owner):m_pOwner(owner),
				m_pCurrentState(NULL),
				m_pPreviousState(NULL),
				m_pGlobalState(NULL)
			{}

			virtual ~StateMachine() {}

			//use these methods to initialize the FSM
			void SetCurrentState(State<TYPE>* s)
			{
				m_pCurrentState = s;
			}
			void SetGlobalState(State<TYPE>* s)
			{
				m_pGlobalState = s;
			}
			void SetPreviousState(State<TYPE>* s)
			{
				m_pPreviousState = s;
			}

			//call this to update the FSM
			void  Update()const
			{
				//if a global state exists, call its execute method, else do nothing
				if(m_pGlobalState)   m_pGlobalState->Execute(m_pOwner);

				//same for the current state
				if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
			}
			//Checks if valid state
			bool  HandleMessage(const Telegram& msg)const
			{
				//first see if the current state is valid and that it can handle
				//the message
				if (m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
				{
					return true;
				}

				//if not, and if a global state has been implemented, send
				//the message to the global state
				if (m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
				{
					return true;
				}

				return false;
			}

			//change to a new state
			void  ChangeState(State<TYPE>* pNewState)
			{
				assert(pNewState && "<StateMachine::ChangeState>:trying to assign null state to current");

				//keep a record of the previous state
				m_pPreviousState = m_pCurrentState;

				//call the exit method of the existing state
				m_pCurrentState->Exit(m_pOwner);

				//change state to the new state
				m_pCurrentState = pNewState;

				//call the entry method of the new state
				m_pCurrentState->Enter(m_pOwner);
			}

			//change state back to the previous state
			void  RevertToPreviousState()
			{
				ChangeState(m_pPreviousState);
			}

			/*/returns true if the current state's type is equal to the type of the class passed as a parameter.
			bool  isInState(const State<TYPE>& st)const
			{
			if (typeid(*m_pCurrentState) == typeid(st)) return true;
			return false;
			}
			*/
			//Public access (Read Only)
			State<TYPE>*  CurrentState()  const
			{
				return m_pCurrentState;
			}
			//Public access (Read Only)
			State<TYPE>*  GlobalState()   const
			{
				return m_pGlobalState;
			}
			//Public access (Read Only)
			State<TYPE>*  PreviousState() const
			{
				return m_pPreviousState;
			}

			/*/only ever used during debugging to grab the name of the current state

			std::string         GetNameOfCurrentState()const
			{
			std::string s(typeid(*m_pCurrentState).name());

			//remove the 'class ' part from the front of the string
			if (s.size() > 5)
			{
			s.erase(0, 6);
			}

			return s;
			}
			*/
		};

	}
}
#endif
