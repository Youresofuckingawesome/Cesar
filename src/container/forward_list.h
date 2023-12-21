#pragma once

#include <container.h>

namespace Ces {

	template<typename __type>
	class Forward_List : public Container<__type>
	{
	public:
		Forward_List() = default;
		
		void Add(__type item) override;
		void Delete(__type item) override;
		void DeleteByIndex(unsigned int index) override;

		__type operator[](unsigned int index) const override;
		__type& operator[](unsigned int index) override;
		
	private:
		std::forward_list<__type> m_Cont;
	}
	
}
