#pragma once

#include <container.h>

namespace Ces {

	template<typename __type, unsigned int __capacity>
	class Array : public Container<__type>
	{
	public:
		Array() = default;

		void Add(__type item) override;
		void Delete(__type item) override;
		void DeleteByIndex(unsigned int index) override;

		inline size_t Size() const override { return m_Cont.size(); }

		__type operator[](unsigned int index) const override;
		__type& operator[](unsigned int index) override;
		
	private:
		std::array<__type, __capacity> m_Cont;
	};

}
