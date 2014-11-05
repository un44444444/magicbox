'use strict';

/* Services */

var magicboxServices = angular.module('magicboxServices', ['ngResource']);

magicboxServices.factory('AboutService', ['$resource',
  function($resource){
    var baseurl = 'http://127.0.0.1:8088/';
    return $resource(baseurl+'recvSmgpSubmitRpt/:areaId', {}, {
      getarea: {method:'GET', params:{areaId:''}, isArray:true}
    });
  }
]);
