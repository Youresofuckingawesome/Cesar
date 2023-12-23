#include <iostream>

#include <fabriccontainer.h>

int main(void)
{
    Ces::FabricContainer<float> container(Ces::ContainerType::Array);
    container.GenerateContent(12);
	auto cont = container.GetContainer();

    for (int i = 0; i < cont->Size(); i++)
    {
        std::cout << cont->GetElement(i) << std::endl;
    }

    return 0;
}
