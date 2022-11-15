#include "activities.h"

std::vector<Activity> get_max_activities(const std::vector<Activity>& activities) {
    int max_size = 0;                              // счетчик для нахождения цепочки макс. длины
    std::vector<Activity> answer;                 // вектор записи окончательного ответа
    for (int k = 0; k < activities.size(); k++)  // перебираем начальные элементы цепочки
    {        
        int result_size = 0;                               // счетчик длины вектора промежуточного ответа
        Activity buffer = activities[k];                  // буфер для записи последнего обьекта записанного в итоговый вектор
        std::vector<Activity> result;                    // вектор записи промежуточного ответа
        result.push_back(buffer);                       // добавляем в вектор начальный элемент цепочки
        result_size += (buffer.finish - buffer.start); // добавляем к счетчику длину первого элемента цепочки
        for (int i = 0; i < activities.size(); i++)   // два цикла для составления цепочки интервалов
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

        if (result_size > max_size) {           // фильтр
            max_size = result_size;
            answer = result;
        }
        result.clear();
    }
    return answer;
}