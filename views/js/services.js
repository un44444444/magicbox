'use strict';

/* Services */

var magicboxServices = angular.module('magicboxServices', ['ngResource']);

magicboxServices.factory('Phone', ['$resource',
  function($resource){
    return $resource('phones/:phoneId.json', {}, {
      query: {method:'GET', params:{phoneId:'phones'}, isArray:true}
    });
  }]);
