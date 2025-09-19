class TaskManager {
public:
    struct Manager {
        int userid;
        int taskid;
        int priority;
    };

    struct Compare {
        bool operator()(const Manager &a, const Manager &b) const {
            if (a.priority != b.priority) return a.priority < b.priority; 
            return a.taskid < b.taskid; // larger taskId wins on tie
        }
    };

    priority_queue<Manager, vector<Manager>, Compare> pq;
    unordered_map<int, Manager> record;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            Manager m{t[0], t[1], t[2]};
            pq.push(m);
            record[t[1]] = m;
        }
    }

    void add(int userId, int taskId, int priority) {
        Manager m{userId, taskId, priority};
        pq.push(m);
        record[taskId] = m;
    }

    void edit(int taskId, int newPriority) {
        auto it = record.find(taskId);
        if (it == record.end()) return;
        Manager updated{it->second.userid, taskId, newPriority};
        pq.push(updated);
        record[taskId] = updated;
    }

    void rmv(int taskId) {
        record.erase(taskId); // lazy removal
    }

    int execTop() {
        while (!pq.empty()) {
            Manager top = pq.top(); pq.pop();
            auto it = record.find(top.taskid);
            if (it == record.end()) continue; 
            if (it->second.priority != top.priority || it->second.userid != top.userid) continue; 
            record.erase(it);
            return top.userid;
        }
        return -1;
    }
};
