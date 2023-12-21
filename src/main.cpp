#include <iostream>

#include <generator.h>
#include <fabriccontainer.h>

int main(void)
{
    Ces::FabricContainer<int> container(Ces::ContainerType::Vector);
    container.GenerateContent(10000);
	auto& cont = container.GetContainer();

    for (int i = 0; i < cont.Size(); i++)
    {
        std::cout << cont[i] << std::endl;
    }

    return 0;
}
