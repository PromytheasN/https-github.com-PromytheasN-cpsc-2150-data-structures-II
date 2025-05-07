# Movie Recommendation Engine (C++)

A simple yet effective graph-based recommendation engine built in C++. It uses a bipartite graph model to connect users and movies via rating edges, and recommends movies based on aggregate similarity scores derived from shared user behavior.

## Files

- `RecommendationEngine.h` – Core graph class handling movie/user rating data and recommendation logic.
- `testRecommendationEngine.cpp` – Main driver file that reads ratings and interacts with the user.
- `MovieRatings.txt` – Sample dataset of user–movie ratings in the format: `UserID MovieID Rating`.

## How It Works

This engine builds a bipartite graph:
- **Users ↔ Movies**, where edges are weighted by ratings (1–5).
- When a user inputs a recently watched movie, the engine:
  1. Finds all users who rated that movie.
  2. Looks at other movies they rated.
  3. Calculates a similarity score: `watchedRating × otherMovieRating`.
  4. Aggregates and sorts these scores.
  5. Returns top recommended movies.

## Run the Program

Compile and execute:

```bash
g++ testRecommendationEngine.cpp -o recommender
./recommender
