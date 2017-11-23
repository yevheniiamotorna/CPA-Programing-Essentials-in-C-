﻿#include <iostream>
#include <math.h>
#include <string>


std::string ForDPatternNLeng(std::string pattern, std::string sentence)//find std::string DD...D pattern
{
    std::string result;
    int k = 0;
    for(int i = 0; i < pattern.length(); i++)
        for(int j = k; j < sentence.length(); j++)
            if(pattern.substr(i, 1) == "D")
                if((sentence.substr(j, 1).compare(pattern.substr(i, 1)) <= -11) && sentence.substr(j, 1).compare(pattern.substr(i, 1)) >= -20)
                {
                    result += sentence.substr(j, 1);
                    k = j + 1;
                    j = sentence.length();
                }
    return result;
}

std::string ForAPatternNLeng(std::string pattern, std::string sentence)//findstd::string matching AA...A pattern
{
   std::string result;
    for(int j = 0; j < sentence.length(); j++)
        for(int i = 0; i < pattern.length(); i++)
            if(result.length() == pattern.length())
                return result;
            else
            {    
                if(sentence.substr(j, sentence.length()).substr(i, 1).compare("A") >= 0 && sentence.substr(j, sentence.length()).substr(i, 1) != " ")
                    result += sentence.substr(j, sentence.length())[i];
                else
                {
                    result = "";
                    break;
                }
            }
    return result;
}

std::string ForQMPatternNLeng(std::string pattern, std::string sentence, std::string part)//findstd::string matching ??...? pattern
{
    int n = sentence.find(part) + part.length();//переменная тупо что б понятно было
    return sentence.substr(n, pattern.length());
}

std::string ForLCLPatternNLeng(std::string pattern, std::string sentence)//findstd::string matching lower-case leters pattern
{
   std::string result;
    int k = 0;
    for(int i = 0; i < pattern.length(); i++)
        for(int j = k; j < sentence.length(); j++)
            if(sentence[j] == pattern[i] || abs(std::string(1, sentence[j]).compare(std::string(1, pattern[i]))) == 32)
            {   
                result += sentence[j];
                i++;
                if(result.length() == pattern.length())
                    return result;
            }
            else
            {
                i = 0;
                result = "";
            }
    return result;
}

std::string FindAlg(std::string pattern, std::string sentence, std::string part)
{
    int value = pattern.substr(0, 1).compare("A");
    switch(value)
    {
        case 0:
            return ForAPatternNLeng(pattern, sentence);
        case 3:
            return ForDPatternNLeng(pattern, sentence);
        case -2:
            return ForQMPatternNLeng(pattern, sentence, part);
        default:
            return ForLCLPatternNLeng(pattern, sentence);
    }
}
int main()
{   
    std::string pattern, sentence, result = "", part;
    std::cout << "Input pattern please" << std::endl;
    getline(std::cin, pattern);
    std::cout << "Input sentence please" << std::endl;
    getline(std::cin, sentence);
    int k = 0;
    int i = 0;
    std::cout << "The parts of sentence that matching your pattern is:" << std::endl;
    //проверяем каждый сабстринг длинной шаюлона соответствует ли он шаблону
    for(int j = 0; j < sentence.length() - pattern.length() + 1; j++)
    {
        //цикл для разбития шаблона на части
        do
        {
            part = pattern.substr(k, i - k + 1);
            i++;
        }while(pattern[i] == pattern[k]);
        k = i;//для перехода на следующую часть шаблона
        if(FindAlg(part, sentence.substr(j, pattern.length()), result).length() < part.length())//проверяем соответствует ли найденное выражение части шаблона
        {
            //если нет, то обнуляем
            result = "";
            i = 0;
            k = 0;
        }
        else
        {
            result += FindAlg(part, sentence.substr(j, pattern.length()), result);
            if(result.length() == pattern.length())
            {
                if(result == sentence.substr(j, pattern.length()))
                    std::cout << result << std::endl;
                result = "";//в случае успеха обнуляем все, потому что в предложении 
                //может находиться несколько частей соответствующих шаблону
                i = 0;
                k = 0;
            }
            else//на данном этапе не все части шаблона проверенны, 
            //для каждой части предложения(тоесть значения j) надо проверить все части,
            //если для первой части шаблона проверка успешна
                j--;
        }
    }
    return 0;
}