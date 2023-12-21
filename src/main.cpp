#include <iostream>

#include <fabriccontainer.h>

int main(void)
{
    Ces::FabricContainer<int> container(Ces::ContainerType::Vector);
    container.GenerateContent(10000);

    for (int i = 0; i < container.GetContainer()->Size(); i++)
    {
        std::cout << container.GetContainer()[i] << std::endl;
    }

    return 0;
}