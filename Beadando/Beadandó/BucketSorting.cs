using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading.Tasks;

namespace ConsoleApp
{
    public class Program
    {
        public static void BucketSort(double[] data, int bucketCount)
        {
            var buckets = new List<double>[bucketCount];
            for (int i = 0; i < bucketCount; i++)
                buckets[i] = new List<double>(data.Length / bucketCount);

            var min = double.MaxValue;
            var max = -double.MaxValue;

            for (int i = 0; i < data.Length; i++)
            {
                min = Math.Min(min, data[i]);
                max = Math.Max(max, data[i]);
            }

            for (int i = 0; i < data.Length; i++)
            {
                var idx = Math.Min(bucketCount - 1, (int)(bucketCount * (data[i] - min) / (max - min)));
                buckets[idx].Add(data[i]);
            }

            Parallel.For(0, bucketCount, new ParallelOptions { MaxDegreeOfParallelism = 8 }, i => buckets[i].Sort());

            var index = 0;
            for (var i = 0; i < bucketCount; i++)
                for (var j = 0; j < buckets[i].Count; j++)
                    data[index++] = buckets[i][j];
        }

        public static void Main(string[] args)
        {
            for (int algo = 0; algo < 2; algo++)
            {
                var random = new Random(0);
                var sw = Stopwatch.StartNew();

                for (int i = 0; i < 50000; i++)
                {
                    var n = random.Next(20000, 200000);
                    var data = new double[n];
                    for (int j = 0; j < data.Length; j++)
                        data[j] = 2 * random.NextDouble() - 1;

                    switch (algo)
                    {
                        case 0:
                            //Array.Sort(data);
                            break;

                        case 1:
                            BucketSort(data, n / 200);
                            break;
                    }
                }

                Console.WriteLine($"{(algo == 0 ? "Array.Sort" : "BucketSort")}; {sw.ElapsedMilliseconds}");
            }
        }
    }
}