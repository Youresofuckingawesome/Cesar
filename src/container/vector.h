#pragma once

#include <container.h>

namespace Ces {

	template<typename __type>
	class Vector : public Container<__type>
	{
	public:
		Vector() = default;

		void Add(__type item) override;
		void Delete(__type item) override;
		void DeleteByIndex(unsigned int index) override;

		__type operator[](unsigned int index) const override;
		__type& operator[](unsigned int index) override;
		
	private:
		std::vector<__type> m_Cont;
	};

}
