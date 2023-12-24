#include <iostream>

#include <fabriccontainer.h>

int main(void)
{
    // TODO: Добавить поиск максимального и минимального элемента в контейнере.
    // TODO: Добавить выборку типа данных и контейнера через imgui.
    // TODO: Сделать универсальную отсчитывалку времени.
    Ces::FabricContainer<float> container(Ces::ContainerType::Array);
    container.GenerateContent(12);
    auto cont = container.GetContainer();

    for (int i = 0; i < cont->Size(); i++)
    {
        std::cout << cont->GetElement(i) << std::endl;
    }

    return 0;
}