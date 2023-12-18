#pragma once

#include <array>
#include <vector>
#include <forward_list>

namespace Ces {

	enum class ContainType { Vector, Array, List };

	template<typename __type>
	class Container
	{
	public:
		Container() = default;
		virtual ~Container() = default;

		virtual void Add(__type item) = 0;
		virtual void Delete(__type item) = 0;
		virtual void DeleteByIndex(unsigned int index) = 0;

		virtual __type operator[](unsigned int index) const = 0;
		virtual __type& operator[](unsigned int index) = 0;
	};

	class FabricContainer
	{

	};
}