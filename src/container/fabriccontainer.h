#pragma once

#include <container.h>
#include <vector.h>
#include <array.h>

namespace Ces {

	enum class ContainerType { Vector, Array, List };

	template<typename __type>
	class FabricContainer
	{
	public:
		FabricContainer(ContainerType type)
		{
			switch (type)
			{
			case ContainerType::Vector:
				break; // TODO: Create vector abstract
			case ContainerType::Array:
				break; // TODO: Create array abstract
			case ContainerType::List:
				break; // TODO: Create list abstract
			}
		}

		std::unique_ptr<Container<__type>>& GetContainer() const { return m_Cont; }

	private:
		std::unique_ptr<Container<__type>> m_Cont;
	};

}
