# Write your MySQL query statement below
SELECT score,
Dense_Rank() over (ORDER BY score DESC) as 'rank'
FROM Scores;