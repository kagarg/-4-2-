#include "activities.h"

std::vector<Activity> get_max_activities(const std::vector<Activity>& activities) {
    int max_size = 0;                              // ������� ��� ���������� ������� ����. �����
    std::vector<Activity> answer;                 // ������ ������ �������������� ������
    for (int k = 0; k < activities.size(); k++)  // ���������� ��������� �������� �������
    {        
        int result_size = 0;                               // ������� ����� ������� �������������� ������
        Activity buffer = activities[k];                  // ����� ��� ������ ���������� ������� ����������� � �������� ������
        std::vector<Activity> result;                    // ������ ������ �������������� ������
        result.push_back(buffer);                       // ��������� � ������ ��������� ������� �������
        result_size += (buffer.finish - buffer.start); // ��������� � �������� ����� ������� �������� �������
        for (int i = 0; i < activities.size(); i++)   // ��� ����� ��� ����������� ������� ����������
        {
            for (int j = 0; j < activities.size(); j++)
            {
                if (buffer.finish <= activities[j].start) {
                    result.push_back(activities[j]);
                    result_size += (activities[j].finish - activities[j].start);
                    buffer = activities[j];
                    break;
                }
            }
        }

        if (result_size > max_size) {           // ������
            max_size = result_size;
            answer = result;
        }
        result.clear();
    }
    return answer;
}