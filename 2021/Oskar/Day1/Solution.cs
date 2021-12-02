using System;

namespace Solution
{
    class Solution
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Challenge1.Solution());
            Console.WriteLine(Challenge2.Solution());
            Console.ReadKey();
        }
    }
    class Challenge1
    {
        public static int Solution()
        {
            int increases = 0;
            int prev_value;
            int current_value;

            string[] lines = System.IO.File.ReadAllLines(@"C:\Users\Oskar\source\repos\AoCd1s1\AoCd1s1\TextFile1.txt");
            prev_value = int.Parse(lines[0]);
            
            for (int i = 1; i < 2000; i++)
            {
                current_value = int.Parse(lines[i]);

                if (current_value > prev_value)
                {
                    increases++;
                }

                prev_value = current_value;
            }

            return increases;
        }
    }
    class Challenge2
    {
        public static int Solution()
        {
            int increases = 0;
            int previous_sum;
            int current_sum;
            int value1;
            int value2;
            int value3;

            string[] lines = System.IO.File.ReadAllLines(@"C:\Users\Oskar\source\repos\AoCd1s1\AoCd1s1\TextFile1.txt");
            value1 = int.Parse(lines[0]);
            value2 = int.Parse(lines[1]);
            value3 = int.Parse(lines[2]);
            previous_sum = value1 + value2 + value3;

            for (int i = 3; i < 2000; i++)
            {
                value1 = value2;
                value2 = value3;
                value3 = int.Parse(lines[i]);
                current_sum = value1 + value2 + value3;

                if (current_sum > previous_sum)
                {
                    increases++;
                }

                previous_sum = current_sum;
            }

            return increases;
        }
    }
}
