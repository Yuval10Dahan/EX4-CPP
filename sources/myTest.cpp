// #include "Character.hpp"
// #include "Team.hpp"
// #include "Point.hpp"
// // #include "doctest.h"
// #include "YoungNinja.hpp"
// #include "OldNinja.hpp"
// #include "TrainedNinja.hpp"
// // #include "Team.hpp"
// #include "Team2.hpp"
// #include "Cowboy.hpp"
// #include <string>
// #include <vector>
// #include <random>
// #include <chrono>
// #include <iostream>

// using namespace std;


// double random_float(double min = -100, double max = 100) 
//     {
//         std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
//         std::uniform_real_distribution<double> distribution(min, max);

//         return distribution(generator);
//     }

//     auto create_yninja = [](double x = random_float(), double y = random_float()) {
//         return new YoungNinja{"Bob", Point{x, y}};
//     };

//     auto create_tninja = [](double x = random_float(), double y = random_float()) {
//         return new TrainedNinja{"Bob", Point{x, y}};
//     };

//     auto create_oninja = [](double x = random_float(), double y = random_float()) {
//         return new OldNinja{"Bob", Point{x, y}};
//     };

//     auto create_cowboy = [](double x = random_float(), double y = random_float()) {
//         return new Cowboy{"Bob", Point{x, y}};
//     };

//     auto random_char(double x = random_float(), double y = random_float()) -> Character * {
//         int flag = static_cast<int>(random_float()) % 4;

//         if (flag == 0) return create_cowboy(x, y);

//         if (flag == 1) return create_yninja(x, y);

//         if (flag == 2) return create_tninja(x, y);

//         return create_oninja(x, y);
//     }

//     auto simulate_battle = [](Team &team, Team &team2) {
//         int i = 0;
//         while (team.stillAlive() && team2.stillAlive()) {
//             if (i % 2 == 0) {
//                 team.attack(&team2);
//             } else {
//                 team2.attack(&team);
//             }
//             i++;
//         }
//     };

//     auto multi_attack = [](int n, Team &attacker, Team &defender) {
//         for (int i = 0; i < n; i++) {
//             if (defender.stillAlive()) {
//                 attacker.attack(&defender);
//             }
//         }
//     };



// // test
// int main()
// {
//     cout << "#############################################################" << endl;

//     // vector<int> vec(10);

//     cout << "#############################################################" << endl;
    
//     Point a(6,2);
//     Point b(0,0);
//     // a.print();

//     cout << "#############################################################" << endl;

//     // Cowboy *c = new Cowboy("yuval", a);
//     // Cowboy *c2 = new Cowboy("cow", b);
//     // cout << c->print() << endl;
//     // int lp = c->getLivePoints();
//     // cout << lp << endl;
//     // cout << c->isAlive() << endl;
//     // cout << c->distance(c2) << endl;
//     // c->hit(3);

//     cout << "#############################################################" << endl;

//     // Cowboy *tom = new Cowboy("Tom", a);
//     // OldNinja *sushi = new OldNinja("sushi", b);

//     // Team team_A(nullptr);
//     cout << "#############################################################" << endl;    

//         // Team team{create_cowboy(-1, -1)};
//         // team.add(create_yninja(0, 0));
//         // team.add(create_oninja(-0.5, -0.5));
//         // team.add(create_tninja(0.5, 0.5));
//         // team.add(create_cowboy());

//         // // CHECK_EQ(team.stillAlive(), 5);

//         // auto young_ninja = create_yninja(0, 0);
//         // auto trained_ninja = create_tninja(1, 1);
//         // auto old_ninja = create_oninja(2, 2);
//         // auto young_ninja2 = create_yninja(3, 3);
//         // auto cowboy = create_cowboy(-6, -6);
// 	    // auto cowboy2 = create_cowboy(-7, -7);
// 	    // auto cowboy3 = create_cowboy(-8, -8);

        
//         // Team team2{young_ninja};
//         // team2.add(trained_ninja);
//         // team2.add(old_ninja);
//         // team2.add(young_ninja2);
//         // team2.add(cowboy);
// 	    // team2.add(cowboy2);
// 	    // team2.add(cowboy3);

//         // // CHECK_EQ(team2.stillAlive(), 7);
//         // cout << team2.stillAlive() << endl; // 7

//         // cout << "1 here" << endl;

//         // multi_attack(2, team, team2);

//         // cout << "2 here" << endl;

//         // // CHECK_FALSE(young_ninja->isAlive()); // Young ninja should be dead
//         // cout << young_ninja->isAlive() << endl;

//         // cout << "3 here" << endl;

//         // // CHECK((trained_ninja->isAlive() && old_ninja->isAlive() &&
//         // //        young_ninja2->isAlive())); // Everyone else should still be alive

//         // cout << ((trained_ninja->isAlive() && old_ninja->isAlive() && young_ninja2->isAlive())) << endl;


//         // cout << "4 here" << endl;


//         // team.attack(&team2);
//         // // CHECK((!trained_ninja->isAlive() && old_ninja->isAlive() &&
//         // //        young_ninja2->isAlive())); // No one should die in the attack

//         // cout << (!trained_ninja->isAlive() && old_ninja->isAlive() && young_ninja2->isAlive()) << endl;


//         // cout << "5 here" << endl;


//         // multi_attack(2, team, team2);
//         // // CHECK_FALSE(trained_ninja->isAlive()); // Trained ninja should be dead
//         // // CHECK((!old_ninja->isAlive() && young_ninja2->isAlive()));

//         // cout << trained_ninja->isAlive() << endl;
//         // cout << (!old_ninja->isAlive() && young_ninja2->isAlive()) << endl;

//         // cout << "6 here" << endl;


//         // multi_attack(4, team, team2);
//         // // CHECK_FALSE(old_ninja->isAlive()); // Old ninja should be dead
//         // // CHECK(!young_ninja2->isAlive());

//         // cout << old_ninja->isAlive() << endl;
//         // cout << !young_ninja2->isAlive() << endl;


//         // cout << "7 here" << endl;


//         // multi_attack(2, team, team2);
//         // // CHECK_NOTHROW(team.attack(
//         // //         &team2)); // The entire enemy team will be dead before every cowboy shoots, the attack should stop and not throw an exception


//         // team.attack(&team2);
        
//         // cout << "8 here" << endl;


//         // // CHECK_FALSE(young_ninja2->isAlive()); // Young ninja should be dead

//         // cout << young_ninja2->isAlive() << endl;


//         // cout << "9 here" << endl;


        
//         // // CHECK_THROWS_AS(team.attack(&team2), std::runtime_error); // Attacking a dead team should throw an exception
    
//         // team.attack(&team2);

//         // cout << "10 here" << endl;


//         cout << "#############################################################" << endl;

//         auto team_c1 = create_cowboy(0, 0);
//         auto team2_c1 = create_cowboy(-2, 0);
//         auto team_c2 = create_cowboy(-3, 0);
//         auto team2_c2 = create_cowboy(1, 0);//
//         auto team2_c3 = create_cowboy(3, 0);//
//         auto team_c3 = create_cowboy(5, 0);//
//         auto team2_c4 = create_cowboy(-5, 0);

//         Team team1{team_c1};
//         team1.add(team_c2);
//         team1.add(team_c3);
//         Team2 team2{team2_c2};
//         team2.add(team2_c1);
//         team2.add(team2_c3);
//         team2.add(team2_c4);

//         cout << "1 here - " << team1.getLeader()->getName() << " , " << team2.getLeader()->getName() << endl;

//         multi_attack(4, team1, team2);

//         cout << "2 here - " << team1.getLeader()->getName() << " , " << team2.getLeader()->getName() << endl;

//         // The captain of team2 is the closest enemy to the captain of team1, and therefore should be dead.
//         // CHECK((!team2_c2->isAlive() && team2_c1->isAlive() && team2_c3->isAlive() && team2_c4->isAlive()));
//         cout << (!team2_c2->isAlive() && team2_c1->isAlive() && team2_c3->isAlive() && team2_c4->isAlive()) << endl;

//         cout << "3 here - " << team1.getLeader()->getName() << " , " << team2.getLeader()->getName() << endl;

//         // At this point, the captain should be team2_c3; hence, the next enemy to be attacked by team2 should team_c3.
//         multi_attack(6, team2, team1);

//         cout << "4 here - " << team1.getLeader()->getName() << " , " << team2.getLeader()->getName() << endl;

//         // CHECK((!team_c3->isAlive() && team_c1->isAlive() && team_c2->isAlive()));
//         cout << (!team_c3->isAlive() && team_c1->isAlive() && team_c2->isAlive()) << endl;

//         cout << "5 here - " << team1.getLeader()->getName() << " , " << team2.getLeader()->getName() << endl;


//         // Killing the new captain
//         while (team2_c3->isAlive()) {
//             team_c1->reload();
//             team_c1->shoot(team2_c3);
//         }

//         cout << "6 here - " << team1.getLeader()->getName() << " , " << team2.getLeader()->getName() << endl;

//         // CHECK((!team2_c2->isAlive() && team2_c1->isAlive() && !team2_c3->isAlive() && team2_c4->isAlive()));
//         cout << (!team2_c2->isAlive() && team2_c1->isAlive() && !team2_c3->isAlive() && team2_c4->isAlive()) << endl;

//         cout << "7 here - " << team1.getLeader()->getName() << " , " << team2.getLeader()->getName() << endl;

//         //Next captain should be team2_c1, hence, the next enemy to be attacked by team2 should team_cc.
//         multi_attack(7, team2, team1);

//         cout << "8 here - " << team1.getLeader()->getName() << " , " << team2.getLeader()->getName() << endl;


//         // CHECK((!team_c3->isAlive() && team_c1->isAlive() && !team_c2->isAlive()));
//         cout << (!team_c3->isAlive() && team_c1->isAlive() && !team_c2->isAlive()) << endl;

//         cout << "9 here - " << team1.getLeader()->getName() << " , " << team2.getLeader()->getName() << endl;

//         while (team1.stillAlive() && team2.stillAlive()) {
//             team1.attack(&team2);
//             team2.attack(&team1);
//         }

//         cout << "10 here - " << team1.getLeader()->getName() << " , " << team2.getLeader()->getName() << endl;

// }