## Week 2 Experiment results

All experiments were done in a more controleld environment:
* **Machine Specs:** 8 cores, 32 GB
* 25x25 grid (40 percent blocked)
* Fixed and controlled cost function - (sleep for 2 ms)
* No 2 threads are running on the same code - `OMP_PROC_BIND=spread`
* No other processes running in the background


__**Baseline: Without any cost function the Sequential code on our experimental setup runs in 18ms**__

Runtime (in ms) for the fixed cost func of 2ms:
* Sequential : 1856, 1855, 1836, 1845, 1841
* 2 Threads : 1697, 1718, 1702, 1708, 1720 
* 4 Threads : 1064, 1086, 1079, 1074, 1079
* 6 Threads : 1093, 1097, 1090, 1090, 1089
* (Plateaus at anything more than the number of diretions - expected!!)

We are not seeing much inprovment in 2 threads because we are exploring 4 directions and the the **cost function is likely not expensive** enough. 
To validate this hyopothesis we ran the code with a little more expensive cost fucntion of 10ms 

We now see an increase in the margin between the sequential code and the one with 2 threads: (Ballpark values listed here)
* Sequntial code: ~9000 ms
* 2 Threads : ~ 8000 ms
* 4 threads : ~5100 ms


