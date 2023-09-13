auto startTime = Clock::now();
auto lastUpdateTime = startTime;
float timeElapsed = 0.0;

while (timeElapsed < 5.0) {
    if (Clock::secs_since(lastUpdateTime) >= 1.0 / FPS) {
        grid -> useRule(timeElapsed);
        timeElapsed = Clock::secs_since(startTime);
        lastUpdateTime = Clock::now();
    }
    // cout << Clock::secs_since(startTime) << endl;
}