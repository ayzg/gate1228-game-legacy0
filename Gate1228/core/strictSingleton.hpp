#ifndef STRICTSINGLETON_HPP
#define STRICTSINGLETON_HPP

#include <iostream>
#include <cassert>

template
<typename T>
class StrictSingleton
{
protected:
	static T* singleton_ptr_;

private:
	StrictSingleton(StrictSingleton<T> &) = default;
	StrictSingleton(StrictSingleton<T> &&) = default;
	StrictSingleton& operator=(StrictSingleton<T>&) = default;
	StrictSingleton& operator=(StrictSingleton<T>&&) = default;

public:
	static T& get();
	static T* get_ptr();

	StrictSingleton(void);
	~StrictSingleton();
};

//!\_________________________________________________________________________________________
//! \attribute: singletonPtr_
//!	\purpose: stores a pointer to the singleton upon instance() call
//!	\usage: access through instance() method
template <typename T>
T* StrictSingleton<T>::singleton_ptr_ = nullptr;

//!\_________________________________________________________________________________________
//! \constructor: StrictSingleton()
//!	\purpose: assert an instance of StrictSingleton hasn't been already invoked
//!			  assign the constructed object to singletonPtr_
template <typename T>
StrictSingleton<T>::StrictSingleton(void)
{
	assert(singleton_ptr_ == nullptr && "StrictSingleton::StrictSingleton() has already been invoked.");
	singleton_ptr_ = static_cast<T*>(this);
}

//!\_________________________________________________________________________________________
//! \constructor: StrictSingleton()
//!	\purpose: assert an instance of StrictSingleton hasn't been already invoked
//!			  assign the constructed object to singletonPtr_
template <typename T>
StrictSingleton<T>::~StrictSingleton(void)
{
	assert(singleton_ptr_ && "StrictSingleton::StrictSingleton() does not exist, cannot delete.");
	singleton_ptr_ = 0;
}

//!\_________________________________________________________________________________________
//! \method:get()
//!	\purpose: deletes entities in entities_ vector, if their exists() flag is true.
//!	\usage: call at the end of a frame to delete unused entities.
template <typename T>
T& StrictSingleton<T>::get()
{
	assert(singleton_ptr_ != nullptr && "StrictSingleton::StrictSingleton() has not been constructed.");
	return *singleton_ptr_;
}

//!\_________________________________________________________________________________________
//! \method:get_ptr()
//!	\purpose: deletes entities in entities_ vector, if their exists() flag is true.
//!	\usage: call at the end of a frame to delete unused entities.
template <typename T>
T* StrictSingleton<T>::get_ptr()
{
	assert(singleton_ptr_ != nullptr && "StrictSingleton::StrictSingleton() has not been constructed.");
	return singleton_ptr_;
}



#endif // STRICTSINGLETON_HPP
