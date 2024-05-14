#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <array>

int cnt = 0;

class Player {
private:
    std::string name;
    int score;
    size_t id;
    size_t num;
    std::unique_ptr<char[]> p;
public:
    void show() const
    {
        std::cout << "이름: " << num << ", 점수: " << score << ", 아이디: " << id << ", 자원수: " << num << '\n';
        std::cout << "저장된 글자: " << p.get() << '\n' << '\n';
    }

    int getScore() const {
        return score;
    }

    size_t getID() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    char* getP() const {
        return p.get();
    }

    size_t getNum() const {
        return num;
    }

    std::ifstream& read(std::ifstream& is) {
        p.reset();
        is.read((char*)(this), sizeof(*this));
        p = std::make_unique<char[]>(num);
        is.read(p.get(), num);
        return is;
    }

    void write(std::ostream& os) {
        os.write((char*)this, sizeof(Player));
        os.write((char*)p.get(), num);
    }

    static Player readFromFile(std::ifstream& file) {
        Player player;

        file.read(reinterpret_cast<char*>(&player), sizeof(Player));
        file.seekg(player.num, std::ios::cur);

        cnt++;
        return player;
    }
};

int main()
{
    // 1번
    std::vector<Player> v;
    v.reserve(2'000'000);

    std::ifstream in{ "2024 STL 과제 파일", std::ios::binary };
    
    /*Player p;
    while (p.read(in))
        v.push_back(p);*/

    while (cnt < 5) {
        Player player = Player::readFromFile(in);
        if (!in.good()) {
            if (in.fail()) {
                std::cerr << "Error reading file." << std::endl;
            }
            break; // 파일 읽기가 실패하거나 파일 끝에 도달했을 때 루프를 종료합니다.
        }
        std::cout << cnt << " :: Name: " << player.getName() << ", ID: " << player.getID() << ", Score: " << player.getScore() << ", 자원수: " << player.getNum() << std::endl;
        v.push_back(std::move(player));
    }

    std::cout << "[가장 마자막 객체]" << '\n';
    v.back().show();

    // 2번
    auto max = std::max_element(v.begin(), v.end(), [](const Player& a, const Player& b) {
        return a.getScore() < b.getScore();
        });
    std::cout << "[점수가 가장 큰 Player]" << '\n';
    max->show();

    int sum = 0;
    double avg = std::accumulate(v.begin(), v.end(), 0.0, [](int sum, const Player& a) {
        return a.getScore() + sum;
        });
    std::cout << "[평균 점수]" << '\n';
    std::cout << avg/v.size() << '\n' << '\n';

    // 3번
    std::array<int, 1'00'000'000> idNum{};

    for (const Player& p : v)
        idNum[p.getID()]++;

    std::ofstream out{ "같은 아이디.txt", std::ios::binary };

    for (const Player& p : v) {
        if (idNum[p.getID()] > 1)
        {
            out.write(p.getName().c_str(), p.getName().size());
            out.write((char*)p.getID(), sizeof(p.getID()) * sizeof(size_t));
        }
    }

    // 4번
    for (Player& p : v)
        std::sort(p.getP(), p.getP() + p.getNum());

    int num = std::count_if(v.begin(), v.end(), [](const Player& player) {
        //조건문
         });

    // 5번
    std::vector<Player> v1 = v;     //id
    std::vector<Player> v2 = v;     //name
    std::vector<Player> v3 = v;     //score

    std::sort(v1.begin(), v1.end(), [](const Player& a, const Player& b) {
        return a.getID() < b.getID();
        });

    std::sort(v2.begin(), v2.end(), [](const Player& a, const Player& b) {
        return a.getName() < b.getName();
        });

    std::sort(v3.begin(), v3.end(), [](const Player& a, const Player& b) {
        return a.getScore() < b.getScore();
        });

    while (true) {
        int comm;
        std::cout << "id 입력: ";
        std::cin >> comm;

        for (const Player& p : v1) {
            if (p.getID() == comm) {
                
            }
        }

        for (const Player& p : v2) {
            if (p.getID() == comm) {

            }
        }

        for (const Player& p : v3) {
            if (p.getID() == comm) {

            }
        }
    }
   
    return 0;
}
