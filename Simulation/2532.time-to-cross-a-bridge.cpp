/*
https://leetcode.com/problems/time-to-cross-a-bridge/description/

A very interesting problem indeed :D

Use a variable `time` to denote the current time.

We maintain 2 queues on each side:
- Ready Queue:
  + workers that arrive at the bridge on this side (after putting/picking) <= current `time`
  + in this queue, **least efficient** workers will be prioritized
- Waiting Queue: '' > current `time`
  + workers that arrive at the bridge on this side (after putting/picking) > current `time`
  + in this queue, earliest workers will be prioritized

At first, I tried to maintain 1 queue on each side, but it was insufficient since we have 2 different priority strategies.

*/

class Worker {
public:
    int arrival, idx, lr, rl, pick, put, move;
    Worker(int arrival, int idx, int lr, int rl, int pick, int put) : arrival(arrival), idx(idx), lr(lr), rl(rl), pick(pick), put(put) {
        move = lr + rl;
    }
};

struct ReadyWorker {
    bool operator() (const Worker& a, const Worker& b) {
        if (a.move != b.move) {
            return a.move < b.move;
        }
        return a.idx < b.idx;
    }
};

struct WaitingWorker {
    bool operator() (const Worker& a, const Worker& b) {
        return a.arrival > b.arrival;
    }
};

class Solution {
public:
    void moveFromWaitingToReadyQueue(priority_queue<Worker, vector<Worker>, ReadyWorker>& ready, priority_queue<Worker, vector<Worker>, WaitingWorker>& waiting, int time) {
        while (!waiting.empty() && waiting.top().arrival <= time) {
            ready.push(waiting.top());
            waiting.pop();
        }
    }
    void travelToOtherSide(priority_queue<Worker, vector<Worker>, ReadyWorker>& thisSide, priority_queue<Worker, vector<Worker>, WaitingWorker>& otherSideWaitingQueue, int& time, bool lr = true) {
        Worker worker = thisSide.top();
        thisSide.pop();
        time = max(time, worker.arrival);
        time += lr ? worker.lr : worker.rl;
        worker.arrival = time + (lr ? worker.pick : worker.put);
        otherSideWaitingQueue.push(worker);
    }

    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<Worker, vector<Worker>, ReadyWorker> left, right;
        priority_queue<Worker, vector<Worker>, WaitingWorker> wleft, wright;

        for (int i = 0; i < k; ++i) {
            auto worker = time[i];
            left.push(Worker(0, i, worker[0], worker[2], worker[1], worker[3]));
        }

        int currentTime = 0, delivered = 0, boxesLeft = n;

        while (delivered < n) {
            moveFromWaitingToReadyQueue(left, wleft, currentTime);
            moveFromWaitingToReadyQueue(right, wright, currentTime);

            // no ready worker on both side. (or could by ready on left side but no boxes left)
            // need to wait for some time until one waiting worker arrives at the bridge.
            if (right.empty() && (left.empty() || boxesLeft == 0)) {
                if (boxesLeft == 0) {
                    // left cannot get the turn anymore, so right is the only choice
                    right.push(wright.top());
                    wright.pop();
                } else {
                    if (!wright.empty() && (wleft.empty() || wright.top().arrival <= wleft.top().arrival)) {
                        right.push(wright.top());
                        wright.pop();
                    } else {
                        left.push(wleft.top());
                        wleft.pop();
                    }
                }
            }
            if (!right.empty()) {
                travelToOtherSide(right, wleft, currentTime, false);
                delivered += 1;
            } else {
                travelToOtherSide(left, wright, currentTime, true);
                boxesLeft -= 1;
            }
        }

        return currentTime;
    }
};
