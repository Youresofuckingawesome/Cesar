#pragma once

#include <memory>

#include <array>
#include <vector>
#include <forward_list>

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

		virtual __type operator[](unsigned int index) const = 0;
		virtual __type& operator[](unsigned int index) = 0;
	};

	enum class ContainerType { Vector, Array, List };

	class FabricContainer
	{
	public:
		FabricContainer(ContainerType type)
		{
			switch (type)
			{
			case ContainerType::Vector:
				m_Cont = std::make_unique<Vector>();
				break;
			case ContainerType::Array:
				break; // TODO: Create array abstract
			case ContainerType::List:
				break; // TODO: Create list abstract
			}
		}

		std::unique_ptr<Container>& GetContainer() const { return m_Cont; }

	private:
		std::unique_ptr<Container> m_Cont;
	};
}