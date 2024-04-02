int maxBottlesDrunk(int numBottles, int numExchange) {
        int maxDrinkBottle=0;
        int emptyBottles=0;
        int fullBottles=numBottles;
        while(fullBottles!=0||emptyBottles>=numExchange){
            if(fullBottles>0){
                emptyBottles+=fullBottles;
                maxDrinkBottle+=fullBottles;
                fullBottles=0;
            }
            else {
               fullBottles+=  1;
                emptyBottles-= numExchange;
                numExchange++;
            }
        }
        return maxDrinkBottle;
    }
