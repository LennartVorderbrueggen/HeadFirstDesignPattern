using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Threading;
using System.Timers;

namespace Utulities.Timer
{
    class Timer
    {
        Stopwatch sw = new Stopwatch();
        bool disposed = false;

        public Timer()
        {
            sw.Start();
        }

        private struct timeElement
        {
            timeElement(long t, string u)
            {
                time = t;
                unit = u;
            }
            public float time { get; set; }
            public string unit { get; set; }
        }

        private timeElement getUnit(timeElement element)
        {
            switch (element.unit)
            {
                case "s":
                    return element;
                case "ms":
                    if (element.time > 1000)
                    {
                        element.time = element.time / 1000;
                        element.unit = "s";
                        getUnit(element);
                        break;
                    }
                    else if (element.time < 1)
                    {
                        element.time = element.time * 1000;
                        element.unit = "µs";
                        getUnit(element);
                        break;
                    }
                    else
                    {
                        return element;
                    }
                case " µs":
                    if (element.time > 1000)
                    {
                        element.time = element.time / 1000;
                        element.unit = "ms";
                        getUnit(element);
                        break;
                    }
                    else
                    {
                        return element;
                    }
                default:
                    break;
            }
            return element;
        }
        // Public implementation of Dispose pattern callable by consumers.
        public void stop()
        {
            sw.Stop();
            timeElement res = new timeElement();
            res.time = sw.ElapsedMilliseconds;
            res.unit = "ms";
            res = getUnit(res);
            Console.WriteLine(String.Format("Time elapsed: {0} {1}", res.time, res.unit));
        }
    }
}
