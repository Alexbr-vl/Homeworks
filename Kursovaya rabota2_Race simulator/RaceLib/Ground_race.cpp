#include "Ground_race.h"

void Ground_race::add_participant(Transport* transport) 
{
    // ���������, �������� �� �� ��������
    if (transport->is_ground_transport()) 
    {
        Race::add_participant(transport);
    }
    else 
    {
        std::cout << "������: ����� �������������� ������ �������� ������������ ��������!\n";
    }
}
