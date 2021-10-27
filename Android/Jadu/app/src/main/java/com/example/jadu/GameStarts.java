package com.example.jadu;

import static java.lang.Thread.sleep;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.WindowManager;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.util.Timer;
import java.util.TimerTask;

public class GameStarts extends AppCompatActivity {
    private TextView play;
    Timer timer;



    ProgressBar pb;
int count=0;


    @Override
protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(R.layout.activity_game_starts);


        play= (TextView) findViewById(R.id.play);
        play.setVisibility(findViewById(R.id.play).INVISIBLE);

pb= (ProgressBar) findViewById(R.id.progressBar);
        timer = new Timer();
Timer t = new Timer();
TimerTask tt = new TimerTask() {
    @Override
    public void run() {
        count++;
        pb.setProgress(count);
    }
};

t.schedule(tt,0,30);


        timer.schedule(new TimerTask() {
            @Override
            public void run() {




                startActivity(new Intent(GameStarts.this, GameActivity.class));

                //Intent intent= new Intent(GameStarts.this, GameActivity.class);
                finish();
            }
        }, 3000);










    }
}