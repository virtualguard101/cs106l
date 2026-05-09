#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

std::vector<int> InitializeVector(int size) {
  std::vector<int> vec;
  for (int i = 0; i < size; i++) {
    int input;
    std::cin >> input;
    vec.push_back(input);
  }
  return vec;
}

void PrintVector(const std::vector<int>& vec) {
  for (const auto& elem : vec) {
    // `.at()` will throw an exception if the index is out of bounds
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

int FindPeakHeat(std::vector<int>& temps) {
  if (!temps.empty()) {
    std::sort(temps.begin(), temps.end());
    return temps.back();
  }
  return -1;
}

std::set<std::string> FindDoubleAgents(
    std::map<std::string, std::set<std::string>> departments) {
  std::set<std::string> double_agents, seen;
  for (const auto& [department, agents] : departments) {
    for (const auto& agent : agents) {
      if (seen.count(agent)) {
        double_agents.insert(agent);
      } else {
        seen.insert(agent);
      }
    }
  }
  return double_agents;
}

int main() {
  // std::vector<int> weekly_forecast = InitializeVector(7);
  std::vector<int> weekly_forecast{10, 20, 30, 40, 50, 60, 70};
  std::cout << "----- Weather Report -----" << '\n';
  PrintVector(weekly_forecast);
  std::cout << "----- Peak Heat -----" << '\n';
  std::cout << FindPeakHeat(weekly_forecast) << '\n';
  std::cout << '\n';

  std::cout << "----- Double Agents -----" << '\n';
  std::map<std::string, std::set<std::string>> departments = {
      {"Department 1", {"Agent 1", "Agent 2", "Agent 3"}},
      {"Department 2", {"Agent 4", "Agent 5", "Agent 1"}},
      {"Department 3", {"Agent 7", "Agent 5", "Agent 9"}},
  };
  std::set<std::string> double_agents = FindDoubleAgents(departments);
  for (const auto& agent : double_agents) {
    std::cout << agent << ' ';
  }
  std::cout << '\n';
  return 0;
}
