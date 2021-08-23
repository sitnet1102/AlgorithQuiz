function solution(table, languages, preference) {
    var answer = '';
    var tableTmp = [];
    var scores = [];
    for(var i=0;i<table.length;i++){
        var tmp = table[i].split(' ');
        tableTmp.push(tmp);
    }
    //console.log(tableTmp);
    for(var i=0;i<tableTmp.length;i++){
        var scoreTmp = 0;
        for(var j=1;j<=5;j++){
            for(var k=0;k<languages.length;k++){
                var check = false;
                if(tableTmp[i][6-j] == languages[k]){
                    scoreTmp = scoreTmp + preference[k] * j;
                    check = true;
                    break;
                }
            }
            
            //console.log(tableTmp[i][6-j]);
        }
        scores.push(scoreTmp);
        //console.log('');
    }
    //console.log(scores);
    var max = 0;
    var maxScore = [];
    for(var i=0;i<scores.length;i++){
        if(scores[i] > max){
            max = scores[i];
            maxScore = [];
            maxScore.push(tableTmp[i][0]);
        }else if(scores[i] == max){
            maxScore.push(tableTmp[i][0]);
        }
    }
    if(maxScore.length == 1){
        answer = maxScore[0];
    }else{
        maxScore.sort();
        answer = maxScore[0];
    }
    //console.log(maxScore);
    return answer;
}