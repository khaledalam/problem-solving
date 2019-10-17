 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2 * 1e5 + 10;
const int inf = (1953125 << 9);

// by: KhaledAlam.net@gmail.com

// START --------------------------------------------
// this function(globVector) copied from online resource to read all files in some directory in C++.
#include <glob.h>
vector<string> globVector(const string& pattern) {
	glob_t glob_result;
	glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);
	vector<string> files;
	for (unsigned int i = 0; i < glob_result.gl_pathc; ++i) {
		files.push_back(string(glob_result.gl_pathv[i]));
	}
	globfree(&glob_result);
	return files;
}
// END ---------------------------------------------

map<char, vector<int>> Basket = {
		{ 'G', { 2, 3, 1 } },
		{ 'F', { 2, 2, 2 } }, 
		{ 'C', { 2, 1, 3 } } 
};

map<char, vector<int>> Hand = {
		{ 'G', { 50, 5, -2 } },
		{ 'F', { 20, 1, -1 } } 
};

const string BASKETBALL = "BASKETBALL";
const string HANDBALL = "HANDBALL";

struct Player {
	double score = 0.0;
	string gameType;
	string name;
	string nickName;
	string teamName;
	int number;
	vector<int> metric;
	char position;
	double getScore() {
		double ret = 0.0;

		if (this->gameType == HANDBALL) {
			ret = Hand[this->position][0];
			for (int i = 0; i < 2; ++i) {
				ret += this->metric[i] * Hand[this->position][1 + i];
			}
			return ret;
		} else if (this->gameType == BASKETBALL) {
			ret = 0;
			for (int i = 0; i < 3; ++i) {
				ret += this->metric[i] * Basket[this->position][i];
			}
		}

		return ret;
	}
};

Player * parsePlayer(const string &s, string gameType) {

	Player *player = new Player();

	string name = "", nick = "", team = "";
	int number;
	char pos;

	int idx = 0;
	while (s[idx] != ';') {
		name += s[idx];
		idx++;
	}
	idx++;
	while (s[idx] != ';') {
		nick += s[idx];
		idx++;
	}
	idx++;
	string num = "";
	while (s[idx] != ';') {
		num += s[idx++];
	}
	idx++;
	number = atoi(num.c_str());
	while (s[idx] != ';') {
		team += s[idx++];
	}
	idx++;
	while (s[idx] != ';') {
		pos = toupper(s[idx++]);
	}
	idx++;

	stringstream ss;
	string x = "";
	for (int i = idx; i < (int) s.length(); ++i) {
		x += (s[i] == ';' ? ' ' : s[i]);
	}
	ss << x;
	int val;
	while (ss >> val) {
		player->metric.push_back(val);
	}

	player->name = name;
	player->nickName = nick;
	player->number = number;
	player->teamName = team;
	player->position = pos;
	player->gameType = gameType;
	player->score = player->getScore();

	return player;
}

// print player details
void debug(Player * player) {
	cout << "Name: " << player->name << endl << "Nickname: " << player->nickName
			<< endl << "Number: " << player->number << endl << "Team: "
			<< player->teamName << endl << "Position: " << player->position
			<< endl << "Score: " << player->score << endl;
	cout << "Metric: ";
	for (auto it : player->metric)
		cout << it << " ";
	cout << endl;
}

map<string, vector<Player*>> players;

Player * searchPlayer(Player * player, string gameType) {

	// search based on unique nickname key
	for (auto &it : players[gameType]) {
		if (it->nickName == player->nickName)
			return it;
	}
	return NULL;
}

void handleWinnerTeam(string gameType) {

	map<string, double> teams;
	for (auto &it : players[gameType]) {
		teams[it->teamName] += it->score;
	}

	double maxx = -1.0;
	string teamWon;
	for (auto &it : teams) {
		if (it.second > maxx) {
			teamWon = it.first;
			maxx = it.second;
		}
	}

	// Add 10 points to all players in Winner team
	for (auto &it : players[gameType]) {
		if (it->teamName == teamWon)
			it->score += 10.0;
	}

}

void ProcessFile() {

	string gameType;
	getline(std::cin, gameType);

	for (char &c : gameType)
		c = toupper(c);

	string line;
	while (getline(std::cin, line)) {

		Player * player = parsePlayer(line, gameType);
		Player * current = searchPlayer(player, gameType);

		if (current == NULL)
			players[gameType].push_back(player);
		else
			current->score += player->getScore();

		// debug(player);
	}

	handleWinnerTeam(gameType);
}

void pickMVP(string gameType) {
	sort(players[gameType].begin(), players[gameType].end(), [](const Player *A, const Player *B) {
		return A->score > B->score;
	});

	Player * MVP = players[gameType].front();

	cout << "\n----------\nMVP (" << gameType << "):\n";
	debug(MVP);
}

int main() {
	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	// globVector("./data/*").front().c_str()
	cout << "in data/ dir:\n";
	for (auto &matchFile : globVector("./data/*")) {
		cout << "file: " << matchFile << endl;
	}

	// deal with first question sample(BASKETBALL)
	FILE * pFile;
	pFile = freopen("./data/data2.in", "r", stdin);

	// Start point
	ProcessFile();

	fclose(pFile);

	pickMVP(BASKETBALL);
//	pickMVP(HANDBALL);

	return 0;

}
