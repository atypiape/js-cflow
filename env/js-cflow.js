importScripts("import.js");
print("js-cflow");

JsCFlowApiError = {};
JsCFlowApiError.prototype = new Error();

JsCFlow = {
    RET_TYPE_VOID: 0,
    RET_TYPE_BOOL: 3,
    RET_TYPE_INT: 4,
    RET_TYPE_STRING: 5,
    RET_TYPE_POINTER: 8,
    validString: function (_arg, _error) {
        if (typeof _arg !== "string") {
            throw new TypeError(_error + " - is not a string");
        }
    }
};

jsCFlowApiCall = jsCFlowApiCall ? jsCFlowApiCall
    : function () { throw new JsCFlowApiError("jsCFlowApiCall"); };


function fopen(_fileName, _mode) {
    JsCFlow.validString(_fileName, "fopen()");
    JsCFlow.validString(_mode, "fopen()");
    jsCFlowApiCall("C:\\Windows\\System32\\msvcrt.dll", "fopen", JsCFlow.RET_TYPE_POINTER, _fileName, _mode);
}

fopen("2.txt", "wb");