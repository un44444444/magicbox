'use strict';

/* Controllers */

var magicboxControllers = angular.module('magicboxControllers', []);

magicboxControllers.controller('MainCtrl', ['$scope',
  function($scope) {
    $scope.phones = [];
    $scope.title = 'main';
  }
]);

magicboxControllers.controller('SsqCtrl', ['$scope',
  function($scope) {
    $scope.title = 'ssq';
    $scope.seq = 1;
    $scope.ssqs = [];
    $scope.orderProp = '-obj.score';
    // when submitting the add form, send the text to the node API
    $scope.createSsq = function() {
      var type = {"c":"ssq","flag":1};
      if (typeof magicbox == "undefined") {
        var result = '{"r":['+$scope.seq+',22,23,24,25,26],"b":8,"ac":5,"score":'+(11*$scope.seq)+'}';
      } else {
        var result = magicbox.generate(type, "20130906");
      }
      $scope.ssqs.push({"_id":$scope.seq,"text":result,"obj":JSON.parse(result)});
      $scope.seq++;
    };
  }
]);

magicboxControllers.controller('AboutCtrl', ['$scope', 'AboutService',
  function($scope, AboutService) {
    $scope.title = 'main';
    $scope.data = AboutService.getarea();
  }
]);

magicboxControllers.controller('SsqDetailCtrl', ['$scope', '$routeParams', 'Ssq',
  function($scope, $routeParams, Ssq) {
    $scope.ssq = Ssq.get({ssqId: $routeParams.ssqId}, function(phone) {
      $scope.mainImageUrl = phone.images[0];
    });

    $scope.setImage = function(imageUrl) {
      $scope.mainImageUrl = imageUrl;
    }
  }
]);
