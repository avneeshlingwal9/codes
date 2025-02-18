let scores = [
    60, 50, 60, 58, 54, 54, 58, 50, 52, 54, 48, 69, 34, 55, 51, 52, 44, 51, 69,
    64, 66, 55, 52, 61, 46, 31, 57, 52, 44, 18, 41, 53, 55, 61, 51, 44,
];
function printAndHigh(score) {
    let high = 0;
    for (let i = 0; i < score.length; i++){
        console.log("Score of " + i + "th solution is " + score[i]);
        if (score[i] > high) {
            high = score[i];
        }
    }
    console.log("Highest score is " + high);
    return high;
}
function findPos(score, high) {
    let ans = [];
    for (let i = 0; i < score.length; i++){
        if (score[i] == high) {
            ans.push(i);
        }
    }
    console.log(ans);
}
let high = printAndHigh(scores);
findPos(scores, high);
function lowestCost(score, cost, high) {
    let ans = 100;
    for (let i = 0; i < cost.length; i++){
        if (score[i] == high && cost[i] < ans) {
            ans = cost[i];
        }
    }
    return ans;
}
