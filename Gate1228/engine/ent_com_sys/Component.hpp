#ifndef COMPONENT_H
#define COMPONENT_H

/*!===============================================================================================
==================================================================================================
\file: Component.hpp																	 
\module: entity_component																 
\project: Simple and Fast Game Engine 2018											     
\author: Anton Yashchenko - www.nton.ca 																  
==================================================================================================
================================================================================================*/

/*!=========================================\INCLUDES\==========================================*/

/*SFML - Simple and Fast Medial Library*/
#include <SFML/Graphics/RenderWindow.hpp>


#define ITCSTR(int) std::to_string(int).c_str()

/*!==========================================\CONTENT\==========================================*/

/*! @class: Component
 *! @purpose: interface for creating components to add to entites */
class Component
{
public:
		virtual void init()							{}
		virtual void update(float m_ft)				{}
		virtual void draw(sf::RenderWindow& target) {}
		virtual void recieve(int message)			{}

		virtual ~Component() = default;		
};

#pragma region  ComponentHelpers

//! @function: getUniqueComponentID()
//! @purpose: Generates a unique identifier for component objects
inline std::size_t getUniqueComponentID() noexcept
{
	static std::size_t last_id{ 0u };
	return last_id++;
}


//! @function: getComponentTypeID()
//! @purpose: gets unique identifier for the component object's type
template <typename T>
inline std::size_t getComponentTypeID() noexcept
{
	static_assert(std::is_base_of<Component, T>::value,"T must inherit from Component");
	static std::size_t type_id{ getUniqueComponentID() };
	return type_id;
}

#pragma endregion 


/*!==========================================\HISTORY\==========================================*/
/*!===============================================================================================

\CurrentVersion 1.0.0: 8/21/2018

==================================================================================================
==================================================================================================

Copyright Anton Yashchenko, 2018

The copyright to the computer program(s) herein
is the property of Anton Yashchenko, Canada.
The program(s) may be used and/or copied only with
the written permission of Anton Yashchenko
or in accordance with the terms and conditions
stipulated in the agreement/contract under which
the program(s) have been supplied.

==================================================================================================
================================================================================================*/
#endif
