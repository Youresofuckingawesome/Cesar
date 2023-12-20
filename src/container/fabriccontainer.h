#pragma once

#include <container/vector.h>
#include <container/container.h>

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
				m_Cont = std::make_unique<Vector>();
				break;
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