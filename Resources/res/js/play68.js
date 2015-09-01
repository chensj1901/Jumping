function play68_init() {
	updateShare(0);
}

function play68_submitScore(score) {
	updateShareScore(score);
	setTimeout( function() { Play68.shareFriend(); }, 1500 )
}

function updateShare(bestScore) {

	var descContent = "快跟我一起用手指指点足球！";
	if(bestScore > 0) {
		shareTitle = "我玩《滚滚足球》过了" + bestScore + "关，动脑的足球最好玩！";
	}
	else{
		shareTitle = descContent;
	}
    window.shareData.tTitle = shareTitle;
//	appid = '';
//	Play68.setShareInfo(shareTitle,descContent);
}

function updateShareScore(bestScore) {
 play68_submitScore(score);
}