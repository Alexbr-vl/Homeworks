#include "Air_race.h"


void Air_race::add_participant(Transport* transport)
{
    // ���������, �������� �� �� ���������
    if (transport->is_air_transport())
    {
        Race::add_participant(transport);
    }
    else
    {
        std::cout << "������: ����� �������������� ������ ��������� ������������ ��������!\n";
    }
}
