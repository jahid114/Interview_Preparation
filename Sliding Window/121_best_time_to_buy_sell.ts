function maxProfit(prices: number[]): number {
    let maxProfit: number = 0;
    let left: number = prices[0];
    let right: number;

    for(let i=1;i<prices.length;i++){
        right = prices[i];
        if(right - left < 0){
            left = prices[i];
        }
        if((right - left)>maxProfit){
            maxProfit = right - left;
        }
    }
    return maxProfit;
};