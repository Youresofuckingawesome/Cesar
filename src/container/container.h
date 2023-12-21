#pragma once

#include <memory>

#include <array>
#include <vector>
#include <list>

namespace Ces {

	template<typename __type>
	class Container
	{
	public:
		Container() = default;
		virtual ~Container() = default;

		virtual void Add(__type item) = 0;
		virtual void Delete(__type item) = 0;
		virtual void DeleteByIndex(unsigned int index) = 0;

		virtual size_t Size() const = 0;

		virtual __type operator[](unsigned int index) const = 0;
		virtual __type& operator[](unsigned int index) = 0;
	};

}