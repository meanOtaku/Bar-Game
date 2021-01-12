#include "raylib.h"
#include <string.h>
#include <iostream>
#include <time.h>

#define UR { ballPositionX_vec = ballPositionX_vec + 10; ballPositionY_vec = ballPositionY_vec - 10; }
#define UL { ballPositionX_vec = ballPositionX_vec - 10; ballPositionY_vec = ballPositionY_vec - 10; }
#define DR { ballPositionX_vec = ballPositionX_vec + 10; ballPositionY_vec = ballPositionY_vec + 10; }
#define DL { ballPositionX_vec = ballPositionX_vec - 10; ballPositionY_vec = ballPositionY_vec + 10; }

#define UR_SP { ballPositionX_vec = ballPositionX_vec + 10 ; ballPositionY_vec = ballPositionY_vec - 10 + random; }
#define UL_SP { ballPositionX_vec = ballPositionX_vec - 10 ; ballPositionY_vec = ballPositionY_vec - 10 + random; }
#define DR_SP { ballPositionX_vec = ballPositionX_vec + 10 ; ballPositionY_vec = ballPositionY_vec + 10 + random; }
#define DL_SP { ballPositionX_vec = ballPositionX_vec - 10 ; ballPositionY_vec = ballPositionY_vec + 10 + random; }

struct PositionRec {
    float X;
    float Y;
};

int main(){
    srand(time(0));
    bool dir = true;
    int random = rand()/1000;
    std::string switch_pos[4] = {"p1", "p2", "upperBar", "lowerBar"};
    std::string switch_current_pos = "p1";
    std::string switch_prev_pos = "lowerBar" ;
    const int WindowWidth = 1280;
    const int WindowHeight = 720;
    Rectangle rec1 = {90, 60, 30, 100};
    Rectangle rec2 = {1170, 550, 30, 100};

    Rectangle rec1_p1 = {85, 60, 10, 600};
    Rectangle rec2_p2 = {1190, 60, 10, 600};
  
    Rectangle line1 = {100, 55, 1100, 5};
    Rectangle line2 = {100, 650, 1100, 5};
    float ballRadius = 20;
    float ballPositionX_vec = 200;
    float ballPositionY_vec = 200;

    int scoreP1 = 0;
    int scoreP2 = 0;
    

    InitWindow(WindowWidth, WindowHeight, "slide");

    SetTargetFPS(60);

    while(!WindowShouldClose()){

        Vector2 ballPosition = {ballPositionX_vec , ballPositionY_vec};
        
        if(IsKeyDown(KEY_S)){
            if(rec1.y <= 540){
                rec1.y = rec1.y + 10 ;
            }
            if(rec1.y <= 550 && rec1.y >= 540 ){
                rec1.y++ ;
            }
        }
        if(IsKeyDown(KEY_W)){
            if(rec1.y >= 70){
                rec1.y = rec1.y - 10 ;
            }
            if(rec1.y >= 60 && rec1.y <= 70){
                rec1.y-- ;
            }
        }
        if(IsKeyDown(KEY_DOWN)){
            if(rec2.y <= 540){
                rec2.y = rec2.y + 10 ;
            }
            if(rec2.y <= 550 && rec2.y >= 540 ){
                rec2.y++ ;
            }
        }
        if(IsKeyDown(KEY_UP)){
            if(rec2.y >= 70){
                rec2.y = rec2.y - 10 ;
            }
            if(rec2.y >= 60 && rec2.y <= 70){
                rec2.y-- ;
            }
        }

        if(CheckCollisionCircleRec(ballPosition, ballRadius, rec1)){
            switch_prev_pos = switch_current_pos;
            switch_current_pos = switch_pos[0];
            dir = true;
            random = rand()/1000;
        }
        
        if(CheckCollisionCircleRec(ballPosition,ballRadius, rec2)){
            switch_prev_pos = switch_current_pos;
            switch_current_pos = switch_pos[1];
            dir = false;
            random = rand()/1000;
        }
        if(CheckCollisionCircleRec(ballPosition,ballRadius, line1)){
            switch_prev_pos = switch_current_pos;
            switch_current_pos = switch_pos[2];
            random = rand()/1000;
        }
        if(CheckCollisionCircleRec(ballPosition,ballRadius, line2)){
            switch_prev_pos = switch_current_pos;
            switch_current_pos = switch_pos[3];
            random = rand()/1000;
        }
        if(CheckCollisionCircleRec(ballPosition,ballRadius, rec1_p1)){
            scoreP1++;
            ballPositionX_vec = 200;
            ballPositionY_vec = 200;
            dir = true;
            switch_current_pos = "p1";
            switch_prev_pos = "lowerBar";
        }
        if(CheckCollisionCircleRec(ballPosition,ballRadius, rec2_p2)){
            scoreP2++;
            ballPositionX_vec = 600;
            ballPositionY_vec = 600;
            dir = false;
            switch_current_pos = "p2";
            switch_prev_pos = "upperBar";
        }




         if(switch_current_pos == "p1"){
            if(switch_prev_pos == "lowerBar")
                UR_SP
            if(switch_prev_pos == "upperBar")
                DR_SP
            if(switch_prev_pos == "p1"){
                if(dir)
                    UR
                else
                    UL
            }
         }
         if (switch_current_pos == "p2" ){
            if(switch_prev_pos == "lowerBar")
                UL_SP
            if(switch_prev_pos == "upperBar")
                DL_SP
            if(switch_prev_pos == "p2"){
                if(dir)
                    UR
                else
                    UL
            }
         }
         if (switch_current_pos == "upperBar"){
            if(switch_prev_pos == "p1")
                DR
            if(switch_prev_pos == "p2")
                DL
            if(switch_prev_pos == "lowerBar"){
                if(dir)
                    DR
                else
                    DL
            }
            if(switch_prev_pos == "upperBar"){
                if(dir)
                    UR
                else
                    UL
            }
         }
         if (switch_current_pos == "lowerBar"){
            if(switch_prev_pos == "p1")
                UR
            if(switch_prev_pos == "p2")
                UL
            if(switch_prev_pos == "upperBar"){
                if(dir)
                    UR
                else
                    UL
            }
            if(switch_prev_pos == "lowerBar"){
                if(dir)
                    UR
                else
                    UL
            }
         }
       
        BeginDrawing();


            ClearBackground(BLACK);
            DrawRectangleLines(100, 55, 1100, 600, WHITE);
            DrawRectangleRec(rec1, WHITE);
            DrawRectangleRec(rec2, WHITE);
            DrawCircleV(ballPosition, ballRadius, WHITE);
            DrawRectangleRec(line1, MAGENTA);
            DrawRectangleRec(line2, MAGENTA);
            
            //for scores
            DrawRectangleRec(rec1_p1, WHITE);
            DrawRectangleRec(rec2_p2, WHITE);

            DrawText(TextFormat("SCORE: P1 = %i  P2 = %i", (int)scoreP2 ,(int)scoreP1), 0, 0, 20, WHITE);

        EndDrawing();
    }
}