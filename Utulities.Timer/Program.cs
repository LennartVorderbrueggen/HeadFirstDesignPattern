using System;
using System.Threading;

namespace Utulities.Timer
{
    class Program
    {
        static void Main(string[] args)
        {
            Timer timer = new Timer();
            Console.WriteLine("Hello World!");
            Thread.Sleep(11269);
            timer.stop();
        }
    }
}
