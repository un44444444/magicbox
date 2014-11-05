'use strict';

/* Services */

var magicboxServices = angular.module('magicboxServices', ['ngResource']);

magicboxServices.factory('AboutService', ['$resource',
  function($resource){
    var baseurl = 'http://r.local/';
    return $resource(baseurl+'areas/:areaId', {}, {
      getallareas: {method:'GET', params:{areaId:''}, isArray:true},
      getarea: {method:'GET', params:{areaId:''}, isArray:false}
    });
  }
]);
