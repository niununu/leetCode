#include <iostream>
class SolutionTestUtil
{
public:
    template <class T>
    static void myPrintVec(std::vector<T> vec)
    {
        for (const auto& item : vec)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    template <class T>
    static bool isSameVector(std::vector<T> vec1, std::vector<T> vec2)
    {
        bool isSame = true;

        auto findDiff = [&isSame, vec1, vec2](){
            isSame = false;
            std::cout << "vec1 :";
            myPrintVec(vec1);

            std::cout << "vec2 :";
            myPrintVec(vec2);
        };

        if (vec1.size() != vec2.size())
        {
            findDiff();
        }
        else
        {
            for (int i = 0; i < vec1.size(); ++i)
            {
                if (vec1[i] != vec2[i])
                {
                    findDiff();
                    break;
                }
            }
        }

        return isSame;
    }
}; // class SolutionTestUtil
