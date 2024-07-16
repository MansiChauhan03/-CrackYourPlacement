class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_fuel = 0;
        int total_cost = 0;
        int current_fuel = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); ++i) {
            total_fuel += gas[i];
            total_cost += cost[i];
        }

        // If total gas is less than total cost, it's impossible to complete the circuit
        if (total_fuel < total_cost) {
            return -1;
        }

        for (int i = 0; i < gas.size(); ++i) {
            current_fuel += gas[i] - cost[i];
            // If current fuel drops below zero, reset the start point
            if (current_fuel < 0) {
                start = i + 1;  // Move start point to the next station
                current_fuel = 0;  // Reset current fuel
            }
        }

        return start;
    }
};
