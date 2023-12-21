#pragma once

#include <container.h>
#include <vector.h>
#include <forward_list.h>
#include <array.h>

#include <generator.h>

namespace Ces {

	enum class ContainerType { Vector, Array, List };

	template<typename __type>
	class FabricContainer
	{
	public:
		FabricContainer(ContainerType type, unsigned int capacity = 10)
		{
			switch (type)
			{
			case ContainerType::Vector:
				m_Cont = Vector<__type>();
				break;
			case ContainerType::Array:
				m_Cont = Array<__type, capacity>();
				break;
			case ContainerType::List:
				m_Cont = List<__type>();
				break;
			}
		}

		void ChangeContainer(ContainerType type)
		{
			Container<__type> oldCont = *m_Cont;
			
			switch (type)
			{
			case ContainerType::Vector:
				m_Cont = Vector<__type>();
				break;
			case ContainerType::Array:
				m_Cont = Array<__type, oldCont.Size()>();
				break;
			case ContainerType::List:
				m_Cont = List<__type>();
				break;
			}

			for (int i = 0; i < oldCont->Size(); i++)
			{
				m_Cont[i] = oldCont[i];
			}
		}

		void GenerateContent(size_t numbers)
		{
			Generator gen;
			
			for (size_t i = 0; i < numbers; i++)
			{
				m_Cont[i] = gen.HardRandom<__type>();
			}
		}

		Container<__type> GetContainer() const { return m_Cont; }

	private:
		Container<__type>* m_Cont;
	};

}
