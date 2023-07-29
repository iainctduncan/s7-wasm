// js file that gets merged into the emscripten generated js

mergeInto(LibraryManager.library, {
    updateHostResults: function(resultsMsgPointer){
        showResults(Module.UTF8ToString(resultsMsgPointer));
    }
});