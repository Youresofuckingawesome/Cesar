#include <forward_list.h>

namespace Ces {

	template<typename __type>
	void List<__type>::Add(__type item)
	{
		m_Cont.push_back(item);
	}

	template<typename __type>
	void List<__type>::Delete(__type item)
	{
		m_Cont.erase(item);
	}

	template<typename __type>
	void List<__type>::DeleteByIndex(unsigned int index)
	{
		m_Cont.erase(m_Cont.begin() + index);
	}

	template<typename __type>
    __type List<__type>::operator[](unsigned int index) const
	{
		return m_Cont[index];
	}

	template<typename __type>
    __type& List<__type>::operator[](unsigned int index)
	{
		return &m_Cont[index];
	}
}
