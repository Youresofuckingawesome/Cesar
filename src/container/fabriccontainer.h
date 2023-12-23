#pragma once

#include <memory>

#include <container.h>
#include <vector.h>
#include <forward_list.h>
#include <array.h>

#include <generator.h>

namespace Ces {

	enum class ContainerType { Vector, Array, List };

	template<typename __type, unsigned int __capacity = 10>
	class FabricContainer
	{
	public:
		FabricContainer(ContainerType type)
		{
			switch (type)
			{
			case ContainerType::Vector:
			    m_Cont = std::make_unique<Vector<__type>>();
				break;
			case ContainerType::Array:
			    m_Cont = std::make_unique<Array<__type, __capacity>>();
				break;
			case ContainerType::List:
				m_Cont = std::make_unique<List<__type>>();
				break;
			}
		}

		void ChangeContainer(ContainerType type)
		{
			Container<__type> oldCont = *m_Cont;
			
			switch (type)
			{
			case ContainerType::Vector:
				m_Cont = std::make_unique<Vector<__type>>();
				break;
			case ContainerType::Array:
				m_Cont = std::make_unique<Array<__type, __capacity>>();
				break;
			case ContainerType::List:
				m_Cont = std::make_unique<List<__type>>();
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
				int num = gen.RandomInteger(0, 100);
				m_Cont->Add(num);
			}
		}

	    Container<__type>* GetContainer() { return m_Cont.get(); }

	private:
		std::unique_ptr<Container<__type>> m_Cont;
	};

}
