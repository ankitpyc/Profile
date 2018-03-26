$(function() {
	$(window).on('shown.bs.modal', function() {
		
		$("#Data li .bar").each( function( key, bar ) {
    var percentage = $(this).data('percentage');
    
    $(this).animate({
      'height' : percentage*10 + '%'
    }, 1000);
  });
		$('a[href="#DataScience"]').on('click', function (e) {
			$("#Data li .bar").each( function( key, bar ) {
    var percentage = $(this).data('percentage');
    
    $(this).animate({
      'height' : percentage*10 + '%'
    }, 1000);
  });
$("#SoftwareDev li .bar").each( function( key, bar ) {
    var percentage = $(this).data('percentage');
    
    $(this).animate({
      'height' : 0 + '%'
    }, 10);
  });

});

	$('a[href="#SoftwareDev"]').on('click', function (e) {
		
	$("#DataScience li .bar").each( function( key, bar ) {
    var percentage = $(this).data('percentage');
    
    $(this).animate({
      'height' : 0 + '%'
    }, 10);
  });


			$("#Software li .bar").each( function( key, bar ) {
    var percentage = $(this).data('percentage');
    
    $(this).animate({
      'height' : percentage*10 + '%'
    }, 1000);
  });


});

		
  

});
	$(window).on('hidden.bs.modal', function() {

			$("#Software li .bar").each( function( key, bar ) {
    var percentage = $(this).data('percentage');
    
    $(this).animate({
      'height' : 0 + '%'
    }, 10);
});
    	$("#Data li .bar").each( function( key, bar ) {
    var percentage = $(this).data('percentage');
    
    $(this).animate({
      'height' : 0 + '%'
    }, 10);
  });
  });


	});